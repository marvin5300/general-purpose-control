#ifndef CHIGHLIGHTER_H
#define CHIGHLIGHTER_H

#include <QSyntaxHighlighter>

class CHighlighter : public QSyntaxHighlighter
{
public:
    CHighlighter(QTextDocument *parent);
    ~CHighlighter();
    void highlightBlock(const QString &text);
};

#endif // CHIGHLIGHTER_H
