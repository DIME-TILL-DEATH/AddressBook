#include "package.h"


namespace net {
Package::Package(PackageType type)
    : m_translationStream {&m_rawData, QIODevice::WriteOnly},
      m_type {type}
{
    // в зависимости от версии QT datastream менялся, поэтому надо указать с какой работаем
    m_translationStream.setVersion(QDataStream::Qt_DefaultCompiledVersion);
}

Package::Package(const QVariant &data, PackageType type)
        : Package(type)
{
    m_data = data;
    fillTranslationStream();
}

PackageType Package::type() const
{
    return m_type;
}

QVariant Package::data() const
{
    return m_data;
}

QByteArray Package::rawData() const
{
    return m_rawData;
}

void Package::fillTranslationStream()
{
    m_translationStream << static_cast<qint32>(m_type)
                        << m_data;

}

QDataStream& operator>>(QDataStream& stream, Package& package)
{
    qint32 type;
    stream >> type;
    package.m_type = static_cast<PackageType>(type);

    QVariant data;
    stream >> data;
    package.m_data = data;

    package.fillTranslationStream();

    return stream;
}
}
