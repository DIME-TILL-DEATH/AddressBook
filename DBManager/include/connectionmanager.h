#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <memory>

namespace db
{
// синглтон Майерса
class ConnectionManager
{
public:
    // подготавливаем Singleton, удаляем конструктор копирования и оператор присваивания
    ConnectionManager(const ConnectionManager&) = delete;
    ConnectionManager& operator=(const ConnectionManager&) = delete;
    ~ConnectionManager();

    static ConnectionManager& instance();
    bool isValid() const;
private:
    ConnectionManager();
    struct ConnectionManagerPrivate;
    std::unique_ptr<ConnectionManagerPrivate> m_d; //deep pointer
};
}
#endif // CONNECTIONMANAGER_H
