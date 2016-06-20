#ifndef KEYBOARDCONTROLLERPRESET_H
#define KEYBOARDCONTROLLERPRESET_H

#include <QHash>

#include "controllers/controllerpreset.h"
#include "controllers/controllerpresetvisitor.h"
#include "controllers/midi/midimessage.h"

class KeyboardControllerPreset : public ControllerPreset {
public:
    KeyboardControllerPreset() {}
    virtual ~KeyboardControllerPreset() {}

    virtual void accept(ControllerPresetVisitor* visitor) {
        if (visitor) {
            visitor->visit(this);
        }
    }

    virtual void accept(ConstControllerPresetVisitor* visitor) const {
        if (visitor) {
            visitor->visit(this);
        }
    }

    virtual bool isMappable() const {
        return true;
    }

    // Get all QKeySequences bound to a given ConfigKey, separated by a given separator
    QString getKeySequencesToString(ConfigKey configKey, QString separator);

    // Get all QKeySequences bound to a given ConfigKey
    QList<QKeySequence> getKeySequences(ConfigKey configKey);

    // Get mapping info filtered by a given group name
    QMultiHash<ConfigValueKbd, ConfigKey> getMappingByGroup(QString targetGroup);

    // Multi-hash of config keys, bound to a specific key sequence
    QMultiHash<ConfigValueKbd, ConfigKey> m_keySequenceToControlHash;
};

typedef QSharedPointer<KeyboardControllerPreset> KeyboardControllerPresetPointer;

#endif