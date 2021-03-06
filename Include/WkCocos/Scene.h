#ifndef __WKCOCOS_SCENE_H__
#define __WKCOCOS_SCENE_H__

//#include "cocos2d.h"
#include "WkCocos/Interface.h"

namespace WkCocos
{
	/**
	* Generic behavior not handle by cocos for our custom scenes.
	*/
	class Scene : public cocos2d::Scene
	{
	public:
		/**
		* implement the "static create()" method manually
		*/
		CREATE_FUNC(Scene);

		/**
		* Destructor
		*/
		virtual ~Scene();

		/**
		* Initialize the scene
		*/
		virtual bool init();

		/**
		* Add UI to manage
		* @param ui Interface to manage
		* @return id of the interface
		*/
		inline std::string addInterface(Interface* ui)
		{
			return addInterface(ui->getFilepath(), ui);
		}
		std::string addInterface(std::string id, Interface* ui);

		/**
		* Remove managed UI
		* @param ui Interface to manage
		* @return the interface removed from the list.
		*/
		Interface* removeInterface(std::string id);
		
		/**
		* Get UI loaded
		* @param filepath filepath or string id of the UI to fetch
		*/
		template <typename UI = Interface>
		inline UI* getInterface(const std::string& filepath) { return dynamic_cast<UI*>(m_ui.at(filepath)); }
		
		/**
		* find UI loaded
		* @param filepath filepath or string id of the UI to fetch
		* @return nullptr if UI was not loaded
		*/
		template <typename UI = Interface>
		inline UI* findInterface(const std::string& filepath) {
			auto ui_it = m_ui.find(filepath);
			if (ui_it == m_ui.end())
			{
				return nullptr;
			}
			else
			{
				return dynamic_cast<UI*>(ui_it->second);
			}
		}

		/**
		* Get the world view
		* @return the world view
		*/
		inline cocos2d::CameraView* getWorldView() const { return m_worldView; }

		/**
		* Get the ui view
		* @return the ui view
		*/
		inline cocos2d::CameraView* getUIView() { return m_uiView; }

		/**
		* Override update to trigger update in all UIs
		*/
		virtual void update(float delta) override;

	protected:
		/**
		* Default constructor.
		* To create a new scene, call "create"
		*/
		Scene();

		/**
		* UI loaded map
		*/
		std::map<std::string, Interface*>		m_ui;

		/**
		* View use for object of the world, such as character
		*/
		cocos2d::CameraView*		m_worldView;

		/**
		* View use for UI, not supposed to move with the world camera
		*/
		cocos2d::CameraView*		m_uiView;
	};
}//namespace WkCocos

#endif //__WKCOCOS_SCENE_H__