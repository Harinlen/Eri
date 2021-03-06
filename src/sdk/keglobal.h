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
#ifndef KEGLOBAL_H
#define KEGLOBAL_H

#include <QObject>

namespace Eri
{
struct KEAudioBufferData
{
    qint64 timestamp;
    int frameCount;
    QByteArray data;
};
struct KEResampleInfo
{
    ;
};
enum KESampleFormat
{
    SampleUnsignInt8,
    SampleSignInt16,
    SampleSignInt32,
    SampleFloat,
    SampleDouble
};
enum KEPlayerStates
{
    StoppedState,
    PlayingState,
    PausedState
};
enum KEMusicStates
{
    NoMusic,
    LoadedMusic,
    BufferingMusic,
    BufferedMusic,
    EndOfMusic,
    InvaildMusic
};
}

using namespace Eri;

class KEGlobal : public QObject
{
    Q_OBJECT
public:
    static KEGlobal *instance();
    ~KEGlobal();
    int channel() const;
    int sampleFormat() const;
    int sampleRate() const;
    void setSampleFormat(int sampleFormat);
    void setSampleRate(int sampleRate);
    void setSamplingConfigure(int sampleFormat,
                              int sampleRate);

signals:
    void updateResampleConfigure();

public slots:

private:
    static KEGlobal *m_instance;
    explicit KEGlobal(QObject *parent = 0);

    //Output resample configure.
    int m_sampleFormat;
    int m_sampleRate;
    int m_channel=2; //This configure is locked.
};

#endif // KEGLOBAL_H
