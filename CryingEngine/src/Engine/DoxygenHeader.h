///
///\file	Doxygen Group\DoxyGroups.h
///
///\brief	Doxygen groups for Crying Engine
///



///\mainpage Crying Engine Documentation
///\section section_intro Introduction
///         Welcome to the documentation site for CRYING ENGINE, a 3D student engine made written in C++ in GAM 374/377 at DePaul based on the AzulCore! This website (and the engine) is a WIP so if you see incomplete / unfinished sections rest assured they're on their way.
///			
///\section section_init Initialization
///			CryingEngine will get most of required major systems running to quickly launch a game app. First let's see what our Initialization does. GameInitialize() found within our CryingEngine::Initialize() will let us set up some Window settings such as the Window name, resolution, and a color to register as clear. Here's an example:
///\code
///void CryingEngine::GameInitialize
///{
///this->setWindowName("Matrices and Movement");
///this->setWidthHeight(800, 600);
///this->SetClearColor(0.4f, 0.4f, 0.8f, 1.0f);
///}
/// //Feel free to customize GameInitialize() for your game's needs
///\endcode
///		
///\section section_intro Demo Intro Scene
///			Here's an example of how to set up a basic scene. We can do this within the CryingEngine's LoadContent() to initialize it. We're using a scene pointer to create a new DemoScene(), DemoScene is simply a class that inherits from Scene so that it can have all the proper mechanisms and behavior automated to get started.
///\code
///void CryingEngine::LoadContent
///{
///	Scene* demoScene = new DemoScene();
/// SceneManager::SetCurrentScene(demoScene);
///
/// SceneManager::Initialize();
///}
///\endcode
///
///
///\section asset_sec Importing Assets/File Locations
///			CryingEngine allows users to import assets through the use of the /Assets/ folder found within the main subfolder. From CryingEngine/Assets, you'll find subfolders labeled Models, Shaders, and Textures, each corresponding to their appropriate asset type. Drag appropriate files here to your import needs. Note: Models should be .azul files, shaders are.glsl, and textures should be .tga!
///			Each asset type has its own associated manager for importing/loading/naming it in as the appropriate object and getting/returning the object created for quick and easy external asset use.
///			Use the LoadAllResources.cpp file/LoadAllResources() function to load these assets and make them usable. Here's an example:
///\code
///void CryingEngine::LoadAllResources()
///{
///		TextureManager::LoadTexture("Megaman_Texture", "../Assets/Textures/stitch.tga"); //desired name, filepath
///		ShaderManager::LoadShader("colorConstantRender", "../Assets/Shaders/colorConstantRender"); //desired name, filepath
///		LoadModel("pModelSpaceFrigate", "../Assets/Models/space_frigate.azul"); //desired name, filepath
///}
///\endcode
///			Now we simply call the appropriate manager's "Get" function to access them by name with their object's full public API!
///\code
///void ExampleClass::ExampleClassConstructor()
///{
///		new Texture* txt;
///		new Shader* shad;
///		new Model* mod;
///
///		txt = TextureManager::GetTexture("Megaman_Texture");
///		shad = ShaderManager::GetShader("colorConstantRender");
///		mod = ModelManager::GetModel("pModelSpaceFrigate");
///}
///\endcode

///\section section_Explore Explore the documentation for more info and specific help with utilizing all systems and capabilities available to you!
///
/// \defgroup     CryingEngine
///
/// \brief        All engine code
///

///
/// \defgroup     Backend Engine 
/// \ingroup      CryingEngine
/// \brief        For the power users who really want to know more and explore what underlying systems and work are done under the hood. Not recommended for beginners!
///

///
/// \defgroup     User
/// \ingroup      CryingEngine
/// \brief        Everything the standard user has access to.
///

///
/// \defgroup     Asset Management
/// \ingroup	  CryingEngine
/// \brief        Relating to all external/internal asset management
///

///
/// \defgroup     Camera
/// \ingroup	  CryingEngine
/// \brief        Relating to all camera classes
///

/// \defgroup     GameObject
/// \ingroup      CryingEngine
/// \brief        Relating to game object class and all associated "-able" classes.
///

///
/// \defgroup     Update
/// \ingroup      GameObject
/// \brief        All "Updatable" associated things within GameObject
///

///
/// \defgroup     Draw
/// \ingroup      GameObject
/// \brief        All "Drawable" associated things within GameObject
///

///
/// \defgroup     Alarms
/// \ingroup      GameObject
/// \brief        All "Alarmable" associated things within GameObject
///


///
/// \defgroup     Input
/// \ingroup      GameObject
/// \brief        All "Inputable" associated things within GameObject
///


///
/// \defgroup     Collisions
/// \ingroup      GameObject
/// \brief        All "Collidable" associated things within GameObject
///

///
/// \defgroup     Scene
/// \ingroup      CryingEngine
/// \brief        All associated classes and members of scene
///


///
/// \defgroup     Time
/// \ingroup      CryingEngine
/// \brief        All time control/time management systems
///

///
/// \defgroup     MathTools
/// \ingroup      CryingEngine
/// \brief        All built-in math functions
///
