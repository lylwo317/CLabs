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
    bmpSurface = SDL_LoadBMP("/Users/kevinxie/CLionProjects/CLabs/avatar.bmp");

    SDL_Texture *tex = NULL;
    tex = SDL_CreateTextureFromSurface(render, bmpSurface);

    //释放已加载的图像
    SDL_FreeSurface(bmpSurface);

    SDL_RenderClear(render);
    SDL_RenderCopy(render, tex, NULL, NULL);
    SDL_RenderPresent(render);

    //暂停
    int quit = 0;
    SDL_Event e;
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 ) // poll for event
        {
            //User requests quit
            if( e.type == SDL_QUIT ) // unless player manually quits
            {
                quit = 1;
            }
        }
    }

    //退出SDL
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
