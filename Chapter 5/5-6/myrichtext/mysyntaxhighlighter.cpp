#include "mysyntaxhighlighter.h"

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument *parent):
    QSyntaxHighlighter(parent)
{

}

//高亮文本块
void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    //字符格式
    QTextCharFormat myFormat;
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);
    //要匹配的字符，这里是"char"单词
    QString pattern = "\\bchar\\b";
    //创建正则表达式
    QRegExp expression(pattern);
    //从位置0开始匹配字符串
    int index = text.indexOf(expression);
    //如果匹配成功，那么返回值为字符串的起始位置，它大于或等于0
    while (index >= 0) {
        //要匹配字符串的长度
        int length = expression.matchedLength();
        //对要匹配的字符串设置格式
        setFormat(index, length, myFormat);
        //继续匹配
        index = text.indexOf(expression, index + length);
    }

}
