#pragma once

#include <QMainWindow>
#include <memory>
#include "../core/Game.h"

class BoardWidget;
class PlayerInfoWidget;
class OperationWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    std::shared_ptr<Game> game_;
    std::shared_ptr<BoardWidget> boardWidget_;
    std::shared_ptr<PlayerInfoWidget> playerInfoWidget_;
    std::shared_ptr<OperationWidget> operationWidget_;

    void setupUi();
    void connectSignals();

private slots:
    void onGameStart();
    void onGameEnd();
    void onMoveMade(int row, int col);
    void onUndoRequested();
};