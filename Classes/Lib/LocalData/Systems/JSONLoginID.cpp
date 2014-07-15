#include "WkCocos/LocalData/Systems/JSONLoginID.h"

#include "WkCocos/LocalData/Comp/LocalData.h"

//including json from cocos
#include "json/document.h"         // rapidjson's DOM-style API
#include "json/stringbuffer.h"
#include "json/writer.h"

namespace WkCocos
{
	namespace LocalData
	{
		namespace Systems
		{
			/**
			* This function will write into json file
			*/
			void JSONLoginID::update(entityx::ptr<entityx::EntityManager> es, entityx::ptr<entityx::EventManager> events, double dt)
			{
				entityx::ptr<Comp::File> file;
				entityx::ptr<Comp::LoginID_v1> loginid;
				for (auto entity : es->entities_with_components(file, loginid))
				{
					rapidjson::Document doc;
					doc.Parse<0>(file->m_contents.c_str());

					//if we want to load data
					if (loginid->m_load_cb)
					{
						//this will pass a null value if it doesnt exists
						rapidjson::Value& loginvalue = doc[loginid->m_name.c_str()];
						if (!loginvalue.IsNull()){
							if (loginvalue.HasMember("user"))
							{
								loginid->m_user = loginvalue["user"].GetString();
							}
							if (loginvalue.HasMember("passwd"))
							{
								loginid->m_passwd = loginvalue["passwd"].GetString();
							}
						}
						loginid->m_load_cb(loginid->m_user, loginid->m_passwd);
					}
					else //write request
					{
						// must pass an allocator when the object may need to allocate memory
						rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

						rapidjson::Value vholder;
						vholder.SetObject();
						vholder.AddMember("user", loginid->m_user.c_str(), allocator);
						vholder.AddMember("passwd", loginid->m_passwd.c_str(), allocator);
						doc.AddMember(loginid->m_name.c_str(), vholder, allocator);

						//TMP debug
						rapidjson::StringBuffer strbuf;
						rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
						doc.Accept(writer);

						file->m_contents = strbuf.GetString();
						CCLOG("new contents :  %s", file->m_contents.c_str());
					}

					//we finished working with this component.
					entity.remove<Comp::LoginID_v1>();
				}
			};

		}//namespace Systems
	}//namespace Loading
}//namespace WkCocos

