/*
 * libpapyros - A QML module and collection of classes used throughout Papyros
 * Copyright (C) 2016 Michael Spencer <sonrisesoftware@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "clipboard.h"

#include <QGuiApplication>

Clipboard::Clipboard(QObject *parent) : QObject(parent), m_clipboard(QGuiApplication::clipboard())
{
    // Nothing needed here
}

QString Clipboard::text() const
{
    return m_clipboard->text();
}
