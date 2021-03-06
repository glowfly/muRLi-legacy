#ifndef CLIENTCOMMANDS_H
#define CLIENTCOMMANDS_H

namespace Murli
{
    namespace Client
    {
        enum CommandType
        {
            MESH_COUNT_REQUEST,
            MESH_UPDATE,
            MOD_REMOVED,
            ANALYZER_UPDATE
        };

        struct CountCommand
        {
            uint32_t meshLedCount;
            uint32_t previousLedCount;
            uint32_t previousNodeCount;
        };

        struct AnalyzerCommand
        {        
            uint8_t volume;
            uint16_t frequency;
        };        

        struct Command
        {
            uint64_t id;
            CommandType commandType;
            union
            {
                CountCommand countCommand;
                AnalyzerCommand analyzerCommand;
            };
        };
    }    
}

#endif // CLIENTCOMMANDS_H