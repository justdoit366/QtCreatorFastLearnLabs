#如果Qt主版本大于4(也就是说当前使用的是Qt5或更高的版本)，则需要添加widgets模块
#因为程序中使用的几个类都包含在widgets模块中，所以需要该行代码。
#直接使用QT += widgets也可以，但为了保持与Qt4的兼容性，建议采用这种方式。
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp
