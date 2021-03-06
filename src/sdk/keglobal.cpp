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
#include "keglobal.h"

KEGlobal::KEGlobal(QObject *parent) :
    QObject(parent)
{
    //Initial the default settings.
    m_sampleFormat=SampleSignInt16;
    m_sampleRate=44100;
}

int KEGlobal::channel() const
{
    return m_channel;
}

int KEGlobal::sampleRate() const
{
    return m_sampleRate;
}

void KEGlobal::setSampleRate(int sampleRate)
{
    //Set the sample rate.
    m_sampleRate = sampleRate;
    //Emit configure updated signal.
    emit updateResampleConfigure();
}

void KEGlobal::setSamplingConfigure(int sampleFormat,
                                    int sampleRate)
{
    //Update the configure.
    m_sampleFormat=sampleFormat;
    m_sampleRate=sampleRate;
    //Emit configure updated signal.
    emit updateResampleConfigure();
}

KEGlobal *KEGlobal::m_instance=nullptr;

KEGlobal *KEGlobal::instance()
{
    return m_instance==nullptr?m_instance=new KEGlobal:m_instance;
}

KEGlobal::~KEGlobal()
{
    ;
}

int KEGlobal::sampleFormat() const
{
    return m_sampleFormat;
}

void KEGlobal::setSampleFormat(int sampleFormat)
{
    //Update the sample format.
    m_sampleFormat = sampleFormat;
    //Emit configure updated signal.
    emit updateResampleConfigure();
}
