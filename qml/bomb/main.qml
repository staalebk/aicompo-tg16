import QtQuick 2.0

Rectangle {
    color: "black"

    signal userMove(string direction)

    Keys.onDownPressed: userMove("DOWN")
    Keys.onUpPressed: userMove("UP")
    Keys.onRightPressed: userMove("RIGHT")
    Keys.onLeftPressed: userMove("LEFT")
    Keys.onSpacePressed: userMove("BOMB")

    focus: true

    // Map background grid
    PlayingField {
        id: playingField
    }

    // List of player sprites
    Repeater {
        model: players
        delegate: PlayerSprite {
            playerId: model.modelData.id
            x: playingField.x + model.modelData.position.x * height
            y: playingField.y + model.modelData.position.y * height
            height: playingField.height / (playingField.rows + 1)
            width: height
        }
    }

    EndScreen {
        opacity: 0
        objectName: "endScreen"
    }

    StartScreen {

    }
}
