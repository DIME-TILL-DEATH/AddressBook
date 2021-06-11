#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "dbtypes.h"
#include <memory>

namespace db {
class Processor
{
public:
    Processor();
    ~Processor();
    std::pair<DBResult, std::vector<DBEntry>> requestTableData(DBTables table);
private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;
};
}
#endif // PROCESSOR_H
