#include <QProcess>
#include <iostream>
#include "vanitygui.h"
#include "ui_vanitygui.h"
#include <sstream>

//TODO Gpu device getter
//TODO gpu platform getter
//TODO local work size getter


vanityGui::vanityGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vanityGui)
{
    ui->setupUi(this);
    //QObject::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(quit()));
    //QObject::connect(ui->limitCheckBox, SIGNAL())
    QObject::connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startPush()));
}

vanityGui::~vanityGui()
{
    delete ui;
}

/* GETTERS */
QString vanityGui::getOneThreeChoice() const
{
    QString oneThreeChoice = ui->oneThreeComboBox->currentText();
    if (oneThreeChoice == "any")
    {
        oneThreeChoice = "*";
        return oneThreeChoice;
    }
    else
    {
        int oneThreeChoiceInt = ui->oneThreeComboBox->currentText().toInt();
        switch (oneThreeChoiceInt)
        {
            case 1: return QString("1");
            case 3: return QString("3");
            default: break;
        }
    }
    return QString("*");
}

QString vanityGui::getPrefixLineEdit() const
{
    QString prefixInput = ui->prefixLineEdit->text();
    if (!prefixInput.isEmpty())
    {
        return prefixInput;
    }
    else
    {
        return QString("*");
    }
}

QString vanityGui::getSuffixLineEdit() const
{
    QString suffixArg = "";
    QString suffixInput = ui->suffixLineEdit->text();
    if (!suffixInput.isEmpty())
    {
       suffixArg + "-s " + suffixInput;
    }
    return suffixArg;
}

QString vanityGui::getGenerateSeed() const
{
    bool generateSeedBool = ui->generateSeedCheckBox->isChecked();
    QString generateSeedStr = (generateSeedBool) ? "--generate-seed " : "";
    return generateSeedStr;
}

QString vanityGui::getUseGpu() const
{
    bool useGpuBool = ui->useGpuCheckBox->isChecked();
    QString useGpuStr = (useGpuBool) ? "-g " : "";
    return useGpuStr;
}

QString vanityGui::getUseCpu() const
{
    bool useCpuBool = ui->useCpuCheckBox->isChecked();
    QString useCpuStr = (useCpuBool) ? "" : "-t 0 ";
    return useCpuStr;
}


QString vanityGui::getLimit() const
{
    QString limitArg = "";
    bool limitBool = ui->limitCheckBox->isChecked();
    if (limitBool)
    {
        limitArg = "-l ";
        QString limitInput = ui->limitSpinBox->text();
        limitArg + limitInput;
    }
    return limitArg;
}

QString vanityGui::getCpuThreads() const
{
    QString cpuThreadsArg = "";
    bool cpuThreadsBool = ui->threadsCpuCheckBox->isChecked();
    if (cpuThreadsBool && ui->useCpuCheckBox->isChecked())
    {
        cpuThreadsArg + "-t " +  ui->threadsCpuSpinBox->text();
    }
    return cpuThreadsArg;
}


/* TOGGLES */

void vanityGui::toggleLimit() const
{
     if (ui->limitCheckBox->isChecked())
     {
         ui->limitSpinBox->setDisabled(false);
     }
     else
     {
         ui->limitSpinBox->setDisabled(true);
     }
}

void vanityGui::toggleGpuDevice() const
{
    if (ui->deviceGpuCheckBox->isChecked())
    {
        ui->deviceGpuSpinBox->setDisabled(false);
    }
    else
    {
        ui->deviceGpuSpinBox->setDisabled(true);
    }
}
void vanityGui::toggleGpuPlatform() const
{
    if (ui->platformGpuCheckBox->isChecked())
    {
        ui->platformGpuSpinBox->setDisabled(false);
    }
    else
    {
        ui->platformGpuSpinBox->setDisabled(true);
    }
}
void vanityGui::toggleGpuWorkSize() const
{
    if (ui->workSizeGpuCheckBox->isChecked())
    {
        ui->workSizeGpuLineEdit->setDisabled(false);
    }
    else
    {
        ui->limitSpinBox->setDisabled(true);
    }
}
void vanityGui::startPush() const
{
    /* gather all getters to build string then send to CLI */
    QString vanityCliPath= "C:\\Users\\Gab\\.cargo\\bin\\nano-vanity.exe";
    QStringList arguments;

    arguments << getGenerateSeed();

    QProcess *vanityCliProcess = new QProcess;
    vanityCliProcess->start(vanityCliPath, arguments);


}
void vanityGui::stopPush() const
{
    /* send ctrl+c request to CLI */
    return;
}

/* Actions */

