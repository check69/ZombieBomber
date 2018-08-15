// Zombie Bomber.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "GfxEngine.h"
#include "World.h"
#include "UI.h"

TGfxEngine *g_pGfxEngine;
TWorld     *g_pWorld;
TUI        *g_pUI;

int _tmain(int argc, _TCHAR* argv[])
{
	argv;
	argc;

	srand (static_cast<unsigned int>(time(0)));

	g_pGfxEngine = new TGfxEngine;
	g_pWorld     = new TWorld;
	g_pUI        = new TUI;

	g_pGfxEngine->init(70);

	if (!g_pWorld->init(70, 3, 3, g_pGfxEngine))
		g_pWorld->setWantsToExit();
	if (!g_pUI->init(g_pWorld))
		g_pWorld->setWantsToExit();

	clock_t ini = 0;

	while (!g_pWorld->getWantsToExit())
	{	
		if ((clock() - ini) >= 50 || !ini)
		{
			g_pGfxEngine->draw();
			g_pWorld->run();
			g_pUI->processInput();

			ini = clock();
			//Sleep(50);
		}
	}

	g_pGfxEngine->setTextColor(FOREGROUND_RED);
	printf("\n Game Over: tu puntuacion es: %i \n\n", g_pWorld->getPuntuacion());
	getchar();

	return 0;
}

