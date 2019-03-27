A C++ game engine I created over the course of 5 and a half months built off a barebones version of DePaul's AZUL core game engine (handled 3D OpenGL rendering, basic 3D math library, Windows app entry point, and basic asset handling) . This project was iterated on through weekly sprints for DePaul's game engine sequence. 
All engine code written by me can be found in the CryingEngine/src/engine folder.

Run the CryingEngine.sln in Visual Studio and press play in debug mode to test out the Battle Tank demo game.

Systems I developed include: 
-Timer/Alarm based event processing
-Camera Manager
-Collision system (B-sphere, AABB and OBB supported) with observer based events using my own added 3D math functions
-GameObject parent class 
-Scene Management + Scene creation
-Terrain (Custom creation by reading height maps + customized collision)
-Input (registration + reading/processing user input)
-Update + Render loop tick processing 
-Collision visualization
-Asset handling (management for models, textures, sounds, UI images/sprites for 2D rendering over 3D)
-MathTools library for all collision math
-Basic 3D sound integration using FMod library

User folder contains: 
- Demo code that I wrote to test and demonstrate engine functionality
- LoadAllResources.cpp for users to tell the engine what assets to import/manage and initialize engine with a scene
- GameInitialize.cpp for setting up barebones Windows app settings

Documentation folder contains:
- Generated files from Doxygen source comments with basic intro/demo on how to use the engine
