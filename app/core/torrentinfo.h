#ifndef TORRENTINFO_H
#define TORRENTINFO_H

#include <QList>
#include <QString>
#include <QDateTime>

struct FileInfo {
	QList<QString> path;
	qint64 length;
};

class TorrentInfo
{
	QString m_errorString;
	void clearError();
	void setError(QString errorString);

	QList<QByteArray> m_announceUrlsList;

	qint64 m_length;
	QByteArray m_torrentName;
	qint64 m_pieceLength;
	QList<QByteArray> m_pieces;

	QDateTime *m_creationDate;
	QString *m_comment;
	QString *m_createdBy;
	QString *m_encoding;

	QList<FileInfo> m_fileInfos;

	QByteArray m_infoHash;

	QString m_creationFileName;

	int m_numberOfPieces;
public:
	QString errorString() const;
	bool loadFromTorrentFile(QString filename);

	const QList<QByteArray> &announceUrlsList() const;

	qint64 length() const;
	const QByteArray &torrentName() const;
	qint64 pieceLength() const;
	const QList<QByteArray> &pieces() const;
	const QByteArray &piece(int pieceIndex) const;

	const QDateTime *creationDate() const;
	const QString *comment() const;
	const QString *createdBy() const;
	const QString *encoding() const;

	const QList<FileInfo>& fileInfos() const;
	bool isSingleFile() const;

	const QByteArray &infoHash() const;

	const QString &creationFileName() const;

	int numberOfPieces() const;
	int bitfieldSize() const;

	TorrentInfo();
	~TorrentInfo();
};

#endif // TORRENTINFO_H
