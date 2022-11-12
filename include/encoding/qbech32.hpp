#pragma once
/**
 *
 **/
#include<QByteArray>
#include <QString>
namespace qencoding{
namespace qbech32
{
namespace SegWit{
QString encode(const QString& hrp, const QByteArray &data, const quint32 witver=0);
std::pair<QString,QByteArray> decode(const QString& bstring);
}

namespace Iota{
QString encode(const QString& hrp, const QByteArray &data);
std::pair<QString,QByteArray> decode(const QString& bstring);
}
}
}
