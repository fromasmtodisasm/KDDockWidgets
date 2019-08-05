/*
  This file is part of KDDockWidgets.

  Copyright (C) 2019 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Sérgio Martins <sergio.martins@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KDDOCKWIDGETS_FRAMEWORKWIDGETFACTORY_H
#define KDDOCKWIDGETS_FRAMEWORKWIDGETFACTORY_H

#include "Frame_p.h"
#include "TitleBar_p.h"
#include "TabWidget_p.h"
#include "widgets/SeparatorWidget_p.h" // TODO: remove

namespace KDDockWidgets {

class FrameworkWidgetFactory {
public:
    virtual ~FrameworkWidgetFactory();

    virtual Frame* createFrame(QWidget *parent = nullptr, Frame::Options = Frame::Option_None) const = 0;
    virtual TitleBar* createTitleBar(Frame *) const = 0;
    virtual TitleBar* createTitleBar(FloatingWindow *) const = 0;
    virtual TabBar* createTabBar(TabWidget *parent = nullptr) const = 0;
    virtual TabWidget* createTabWidget(QWidget *parent) const = 0;
    virtual SeparatorWidget* createSeparator(Anchor *anchor, QWidget *parent = nullptr) const = 0;
};

class DefaultWidgetFactory : public FrameworkWidgetFactory
{
public:
    Frame *createFrame(QWidget *parent, Frame::Options) const override;
    TitleBar *createTitleBar(Frame *) const override;
    TitleBar *createTitleBar(FloatingWindow *) const override;
    TabBar *createTabBar(TabWidget *parent) const override;
    TabWidget *createTabWidget(QWidget *parent) const override;
    SeparatorWidget* createSeparator(Anchor *anchor, QWidget *parent = nullptr) const override;
};

}

#endif
