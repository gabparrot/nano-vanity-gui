#ifndef VANITYGUI_H
#define VANITYGUI_H

#include <QMainWindow>

namespace Ui {
class vanityGui;
}

class vanityGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit vanityGui(QWidget *parent = nullptr);
    ~vanityGui();

    QString getOneThreeChoice() const;
    QString getPrefixLineEdit() const;
    QString getSuffixLineEdit() const;

    QString getGenerateSeed() const;
    QString getUseGpu() const;
    QString getUseCpu() const;
    QString getLimit() const;
    QString getCpuThreads() const;

private slots:
    void toggleLimit() const;
    void toggleGpuDevice() const;
    void toggleGpuPlatform() const;
    void toggleGpuWorkSize() const;

    void startPush() const;
    void stopPush() const;


private:
    Ui::vanityGui *ui;
    long int attemptsDone;
    long int attemptsLeft;
    long int attemptsTotal;
    long int timeLeft;
};

#endif // VANITYGUI_H
