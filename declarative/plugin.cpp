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

#include "plugin.h"

#include <Papyros/KQuickConfig>
#include <Papyros/KQuickWallet>
#include "clipboard.h"

void Plugin::registerTypes(const char *uri)
{
    // @uri Papyros.Core
    Q_ASSERT(uri == QStringLiteral("Papyros.Core"));

    qmlRegisterType<KQuickConfig>(uri, 0, 2, "KQuickConfig");
    qmlRegisterType<KQuickWallet>(uri, 0, 2, "KQuickWallet");
    qmlRegisterType<Clipboard>(uri, 0, 2, "Clipboard");
}
