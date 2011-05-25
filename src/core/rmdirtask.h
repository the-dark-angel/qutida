/****************************************************************************
** Copyright (C) 2011 Andrew Bogdanov.
**
** This file is part of qutida.
**
** qutida is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** qutida is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with qutida.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#ifndef RMDIRTASK_H
#define RMDIRTASK_H

#include <QObject>
#include <QRunnable>
#include <QString>

class RmdirTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    struct Parameters
    {
        QString dir;
    };

    struct Result
    {
        QString dir;
        bool success;
    };

    explicit RmdirTask(const Parameters &param);

    void run();

signals:
    void finished(RmdirTask::Result result);

private:
    Parameters parameters;

    bool rmdirRec(const QString &dir);

};

#endif // RMDIRTASK_H
