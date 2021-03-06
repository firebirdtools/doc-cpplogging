//
// Created by Ivan Shynkarenka on 11.07.2016
//

#include "benchmark/cppbenchmark.h"

#include "logging/layouts/binary_layout.h"
#include "logging/layouts/text_layout.h"

using namespace CppLogging;

BENCHMARK("BinaryLayout")
{
    static BinaryLayout layout;
    static Record record;

    record.logger = "Test logger";
    record.message = "Test message";
    record.buffer.resize(1024, 123);

    layout.LayoutRecord(record);
    context.metrics().AddBytes(record.raw.size());
}

BENCHMARK("TextLayout")
{
    static TextLayout layout;
    static Record record;

    record.logger = "Test logger";
    record.message = "Test message";
    record.buffer.resize(1024, 123);

    layout.LayoutRecord(record);
    context.metrics().AddBytes(record.raw.size());
}

BENCHMARK_MAIN()
