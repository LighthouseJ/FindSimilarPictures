#include "directoryscanner.h"

DirectoryScanner::DirectoryScanner(const QString &dir)
{
    qDebug() << "Scanning dir:" << dir;
    QDir parent = QDir(dir);
    QFileInfoList list = parent.entryInfoList();
    QFileInfo file1 = list.at(0), file2 = list.at(1);

    PuzzleContext context;
    PuzzleCvec cvec1, cvec2;
    puzzle_init_context(&context);
    puzzle_init_cvec(&context, &cvec1);
    puzzle_init_cvec(&context, &cvec2);
    puzzle_fill_cvec_from_file(&context, &cvec1, file1.absoluteFilePath().toStdString().c_str());
    puzzle_fill_cvec_from_file(&context, &cvec2, file2.absoluteFilePath().toStdString().c_str());
    double d = puzzle_vector_normalized_distance(&context, &cvec1, &cvec2, 0);
    if (d < PUZZLE_CVEC_SIMILARITY_THRESHOLD) {
        qDebug() << "files are similar";
    }

    puzzle_free_cvec(&context, &cvec1);
    puzzle_free_cvec(&context, &cvec2);

    puzzle_free_context(&context);
}
