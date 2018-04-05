#!/bin/bash
if [ "$QT" == "" ]; then
    QT=~/Qt/5.10.1/clang_64/bin
fi
QMAKE="$QT/qmake"

autoreconf --install
./configure
make -j8

pushd libxavna/xavna_mock_ui
$QMAKE
make -j8
popd

pushd vna_qt
rm -rf *.app
$QMAKE
make -j8
"$QT"/macdeployqt vna_qt.app -libpath=../libxavna/xavna_mock_ui

cd vna_qt.app/Contents
install_name_tool -add_rpath "@executable_path/../Frameworks" MacOS/vna_qt
install_name_tool -change libxavna_mock_ui.1.dylib @executable_path/../Frameworks/libxavna_mock_ui.1.dylib MacOS/vna_qt
