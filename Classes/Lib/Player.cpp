#include "WkCocos/Player.h"
//including json from cocos
//#include "json/document.h"         // rapidjson's DOM-style API
//#include "json/stringbuffer.h"
//#include "json/writer.h"
namespace WkCocos
{
	/*template <class T>
	std::string Player<T>::get_data_json()
	{
		rapidjson::Document doc;
		doc.SetObject();
		// must pass an allocator when the object may need to allocate memory
		rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

		rapidjson::Value currency;
		currency.SetObject();
		currency.AddMember(sGold, m_gold, allocator);
		currency.AddMember(sGem, m_gem, allocator);
		doc.AddMember(sCurrency, currency, allocator);

		rapidjson::Value alarms;
		alarms.SetArray();

		entityx::ptr<WkCocos::Timer::Comp::ID> id;
		entityx::ptr<WkCocos::Timer::Comp::Alarm> alarm;
		for (auto entity : m_timer->getEntityManager()->entities_with_components(id, alarm))
		{
			rapidjson::Value time;
			time.SetObject();
			time.AddMember(sID, id->m_id.c_str(), allocator);

			time.AddMember(sSec, alarm->m_end.tm_sec, allocator);
			time.AddMember(sMin, alarm->m_end.tm_min, allocator);
			time.AddMember(sHour, alarm->m_end.tm_hour, allocator);
			time.AddMember(sMday, alarm->m_end.tm_mday, allocator);
			time.AddMember(sMon, alarm->m_end.tm_mon, allocator);
			time.AddMember(sYear, alarm->m_end.tm_year, allocator);
			time.AddMember(sWday, alarm->m_end.tm_wday, allocator);
			time.AddMember(sYday, alarm->m_end.tm_yday, allocator);
			time.AddMember(sIsdst, alarm->m_end.tm_isdst, allocator);

			alarms.PushBack(time, allocator);
		}
		doc.AddMember(sAlarms, alarms, allocator);

		//TMP debug
		rapidjson::StringBuffer strbuf;
		rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
		doc.Accept(writer);

		return std::string(strbuf.GetString());
	}
	
	template <class T>
	void Player<T>::set_data_json(std::string data)
	{
		rapidjson::Document doc;
		doc.Parse<0>(data.c_str());
		if (doc.HasParseError())
		{
			//if parse error (also empty string), we ignore existing data.
			doc.SetObject();
		}

		if (doc.HasMember(sCurrency))
		{
			rapidjson::Value& currencyvalue = doc[sCurrency];
			if (!currencyvalue.IsNull())
			{
				if (currencyvalue.HasMember(sGold))
				{
					m_gold = currencyvalue[sGold].GetInt();
				}
				if (currencyvalue.HasMember(sGem))
				{
					m_gem = currencyvalue[sGem].GetInt();
				}
			}
		}
		else //first time there is no save
		{
			m_gold = 424242;
			m_gem = 42;
		}

		if (doc.HasMember(sAlarms))
		{
			rapidjson::Value& alarmsarray = doc[sAlarms];
			if (alarmsarray.Size())
			{
				for (rapidjson::SizeType i = 0; i < alarmsarray.Size(); i++)
				{
					rapidjson::Value& time = alarmsarray[i];

					struct tm temptm;
					temptm.tm_hour = time[sHour].GetInt();
					temptm.tm_isdst = time[sIsdst].GetInt();
					temptm.tm_mday = time[sMday].GetInt();
					temptm.tm_min = time[sMin].GetInt();
					temptm.tm_mon = time[sMon].GetInt();
					temptm.tm_sec = time[sSec].GetInt();
					temptm.tm_wday = time[sWday].GetInt();
					temptm.tm_yday = time[sYday].GetInt();
					temptm.tm_year = time[sYear].GetInt();

					m_timer->setAlarm(time[sID].GetString(), temptm);
				}
			}
		}
	}*/
}
