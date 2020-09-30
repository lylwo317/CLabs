#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

int main(int argc, char *args[])
{
    //声明表面
    SDL_Surface *bmpSurface = NULL;

    //启动SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //设置窗口
    SDL_Window *win = NULL;
    win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    
    SDL_Renderer *ren = NULL;
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //加载图像
    bmpSurface = SDL_LoadBMP("../avatar.bmp");

    SDL_Texture *tex = NULL;
    tex = SDL_CreateTextureFromSurface(ren, bmpSurface);

    //释放已加载的图像
    SDL_FreeSurface(bmpSurface);

    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    //暂停
    SDL_Delay(2000);

    //退出SDL
    SDL_Quit();
    return 0;
}
