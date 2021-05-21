#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

int main(int argc, char *args[])
{
    //声明表面
    SDL_Surface *bmpSurface = NULL;

    //启动SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //创建窗口
    SDL_Window *win = NULL;
    win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    
    //创建渲染器
    SDL_Renderer *render = NULL;
    render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //加载图像到surface
    bmpSurface = SDL_LoadBMP("../avatar.bmp");

    SDL_Texture *tex = NULL;
    tex = SDL_CreateTextureFromSurface(render, bmpSurface);

    //释放已加载的图像
    SDL_FreeSurface(bmpSurface);

    SDL_RenderClear(render);
    SDL_RenderCopy(render, tex, NULL, NULL);
    SDL_RenderPresent(render);

    //暂停
    SDL_Delay(2000);

    //退出SDL
    SDL_Quit();
    return 0;
}
