/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KEPLAYBACKBASE_H
#define KEPLAYBACKBASE_H

#include "kedecoderbase.h"

#include <QObject>

class KEPlaybackBase : public QObject
{
    Q_OBJECT
public:
    explicit KEPlaybackBase(QObject *parent = 0);
    ~KEPlaybackBase();
    virtual void reset()=0;
    virtual bool setDecoder(KEDecoderBase *decoder)=0;
    virtual void start()=0;
    virtual void pause()=0;
    virtual void stop()=0;

signals:
    void playNextPacket();

protected slots:
    virtual void onActionPlayNextPacket()=0;

public slots:
};

#endif // KEPLAYBACKBASE_H
