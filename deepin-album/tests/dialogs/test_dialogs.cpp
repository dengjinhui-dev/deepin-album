#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "application.h"
#include "dialogs/albumcreatedialog.h"
#include "dialogs/albumdeletedialog.h"
#include "widgets/dialogs/imgdeletedialog.h"
#include "controller/exporter.h"

#include <QTestEventList>

TEST(albumcreatedialog, dia1)
{
    AlbumCreateDialog *a = new AlbumCreateDialog;
    ASSERT_TRUE(a->getCreateAlbumName().isEmpty());

    QTestEventList event;
    event.addKeyClick(Qt::Key_Escape);
    event.simulate(a);

    QTest::keyClicks(a->getEdit(), "test1");
    emit a->buttonClicked(0, "");
}

TEST(albumcreatedialog, creatNewAlbum)
{
    AlbumCreateDialog *a = new AlbumCreateDialog;
    QTest::keyClicks(a->getEdit(), "newtestalbum1");
    emit a->buttonClicked(1, "");

    DBManager::instance()->removeAlbum("newtestalbum1");
    ASSERT_FALSE(DBManager::instance()->isAlbumExistInDB("newtestalbum1"));
}

TEST(albumdeletedialog, deletdialog)
{
    AlbumDeleteDialog *d = new AlbumDeleteDialog;
    QTestEventList event;
    event.addKeyClick(Qt::Key_Escape);
    event.simulate(d->m_Delete);
}

TEST(Exporter, exportdialog)
{
    CExportImageDialog *c = new CExportImageDialog;
    c->getQuality();
    c->getSavePath();
    c->getImageType();
    c->getImageFormate();
//    c->showDirChoseDialog();
//    c->showEmptyWarningDialog();
    c->deleteLater();
}
