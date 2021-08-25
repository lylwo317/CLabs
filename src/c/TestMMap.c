//
// Created by kevin on 2021/8/25.
//

//[认真分析mmap：是什么 为什么 怎么用](https://www.cnblogs.com/huxiao-tee/p/4660352.html)


/**
 *         0            4999
 * file:  |--------------|
 *         0                     8190
 * mmap:  |-----------------------|
 *        |                       |
 * 只要mmap映射的区域是涵盖有file的（即使涵盖的file区域不足1页大小），也是能正常读写的。只是超过file区域的读到的都是0,写入的也不会被写入file
 * 如果mmap映射的区域不涵盖file，就会出现SIGBUS错误，而如果大于mmap的大小，就会出现SIGSEGV
 * 如果文件是1.5PageSize大小，然后mmap是5PageSize大小。那么在2PageSize读写都是不会报错的，但是在2-5PageSize内读写就会出现SIGBUS.
 * 并且只有0-1.5PageSize的内容会真正写入文件
 *
 * mmap本质只是映射，只有读写操作才会触发数据拷贝。也就是说SIGBUS只有在读写的时候才会出现
 */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(void) {

    size_t bytesWritten = 0;
    int fd;
    long PageSize;
    const char *text = "This is a test";

    if ((PageSize = sysconf(_SC_PAGE_SIZE)) < 0) {
        perror("sysconf() Error=");
        return -1;
    }

    fd = open("/tmp/mmsyncTest",
              (O_CREAT | O_TRUNC | O_RDWR),
              (S_IRWXU | S_IRWXG | S_IRWXO));
    if (fd < 0) {
        perror("open() error");
        return fd;
    }

    // 创建一个PageSize大小的文件。不然后面strcpy就会出现 SIGBUS 错误
    // 文件不存在（大小为0），或者大小不足1个PageSize，或者大于1个PageSize。对文件进行seek操作。
    // 保证文件有1个PageSize大小
    off_t lastoffset = lseek(fd, PageSize - 1, SEEK_SET);
    bytesWritten = write(fd, "", 1);
    if (bytesWritten != 1) {
        perror("write error. ");
        return -1;
    }


    /* mmap the file. */
    void *address;
    long len;
    off_t my_offset = 0;
    len = PageSize;   /* Map one page */
    address = mmap(NULL, len, PROT_WRITE, MAP_SHARED, fd, my_offset);

    if (address == MAP_FAILED) {
        perror("mmap error. ");
        return -1;
    }
    /* Move some data into the file using memory map. */
    strcpy((char *) address, text);

    /* use msync to write changes to disk. */
    //msync 调用后可以会将strcpy的内容立即写入到磁盘
    if (msync(address, PageSize, MS_SYNC) < 0) {
        perror("msync failed with error:");
        return -1;
    }

    //munmap关闭mmap并且写入到磁盘
    munmap(address, len);

    printf("%s", "msync completed successfully.");

    //关闭打开的文件
    close(fd);
}
