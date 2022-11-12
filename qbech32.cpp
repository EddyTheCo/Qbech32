#include"encoding/qbech32.hpp"
#include"segwit_addr.h"
#include"iota_addr.h"
#include <QStringList>
#include<QDebug>
namespace qencoding{
	namespace qbech32 {
namespace SegWit{
        QString encode(const QString& hrp, const QByteArray& data, const quint32 witver )
		{
            auto result=segwit_addr::encode(hrp.toStdString(),witver,std::vector<uint8_t> (data.begin(), data.end()));
			return QString::fromStdString(result);
		}
		std::pair<QString,QByteArray> decode(const QString& bstring)
		{

			auto list=bstring.split("1");

            auto var=segwit_addr::decode(list[0].toStdString(),bstring.toStdString());

			return std::make_pair(list[0], QByteArray(reinterpret_cast<const char*>(var.second.data()), var.second.size()));
		}
}

namespace Iota{
QString encode(const QString& hrp, const QByteArray &data){
    auto result=iota_addr::encode(hrp.toStdString(),std::vector<uint8_t> (data.begin(), data.end()));
    return QString::fromStdString(result);

}
std::pair<QString,QByteArray> decode(const QString& bstring){
    auto list=bstring.split("1");
    auto var=iota_addr::decode(bstring.toStdString());

    return std::make_pair(list[0], QByteArray(reinterpret_cast<const char*>(var.data()), var.size()));
}
}
	}
}
