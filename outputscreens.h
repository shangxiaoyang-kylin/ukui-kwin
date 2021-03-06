/********************************************************************
 UKUI-KWin - the UKUI3.0 window manager
 This file is part of the UKUI project
 The ukui-kwin is forked from kwin
    
Copyright (C) 2014-2020 kylinos.cn

 KWin - the KDE window manager
 This file is part of the KDE project.

Copyright 2018 Roman Gilg <subdiff@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*********************************************************************/
#ifndef KWIN_OUTPUTSCREENS_H
#define KWIN_OUTPUTSCREENS_H

#include "screens.h"

namespace KWin
{

class AbstractOutput;

/**
 * @brief Implementation for backends with Outputs
 */
class UKUI_KWIN_EXPORT OutputScreens : public Screens
{
    Q_OBJECT
public:
    OutputScreens(Platform *platform, QObject *parent = nullptr);
    ~OutputScreens() override;

    void init() override;
    QString name(int screen) const override;
    bool isInternal(int screen) const override;
    QSizeF physicalSize(int screen) const override;
    QRect geometry(int screen) const override;
    QSize size(int screen) const override;
    qreal scale(int screen) const override;
    float refreshRate(int screen) const override;
    void updateCount() override;
    int number(const QPoint &pos) const override;

protected:
    Platform *m_platform;

private:
    AbstractOutput *findOutput(int screen) const;
};

}

#endif // KWIN_OUTPUTSCREENS_H
