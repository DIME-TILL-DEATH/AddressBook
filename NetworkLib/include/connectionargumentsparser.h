#ifndef CONNECTIONARGUMENTSPARSER_H
#define CONNECTIONARGUMENTSPARSER_H

#include <QCommandLineParser>

namespace net {
class ConnectionArgumentsParser
{
public:
    explicit ConnectionArgumentsParser(const QCoreApplication& app);

    const QCommandLineParser &parser() const;

    const QString &hostArgument() const;

    const QString &portArgument() const;

private:
    QCommandLineParser m_parser;
    QString m_hostArgument;
    QString m_portArgument;
};
}
#endif // CONNECTIONARGUMENTSPARSER_H
