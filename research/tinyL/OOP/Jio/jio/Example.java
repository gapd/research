package jio;

import java.awt.Color;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.JOptionPane;

/**
 * リスト表現を用いた入出力「ペン←→シリアライズ(直列化)表現←→ファイル」の例題プログラム。
 */
public class Example extends Object
{
	/**
	 * ペンをシリアライズ(直列化)表現にしてファイルに保存する例題プログラム。
	 * 逆にファイルに保存されたシリアライズ(直列化)表現を読み込んでペンを作る例題プログラム。
	 */
	public static void main(String[] arguments)
	{
		// ペンのオブジェクトを作る。
		Pen aPen = new Pen();
		aPen.position(100, 200);
		aPen.color(Color.orange);
		aPen.nib(3);

		// ペンのオブジェクトを書き込む。
		aPen = Example.write(aPen);
		if (aPen == null) { return; }

		String aString = "Writing was finished:\n" + aPen.toString();
		System.out.println(aString);
		JOptionPane.showMessageDialog(null, aString, "Notify", JOptionPane.PLAIN_MESSAGE);

		// ペンのオブジェクトを読み込む。
		aPen = Example.read();
		if (aPen == null) { return; }

		aString = "Reading was finished:\n" + aPen.toString();
		System.out.println(aString);
		JOptionPane.showMessageDialog(null, aString, "Notify", JOptionPane.PLAIN_MESSAGE);
		
		return;
	}
	
	/**
	 * ペンのオブジェクトをファイルに書き込む。
	 */
	public static Pen write(Pen aPen)
	{
		// ファイル名として用いる日時の文字列を作る。
		Date aDate = new Date();
		SimpleDateFormat aFormat = new SimpleDateFormat("yyyyMMddHHmmss");
		String aString = aFormat.format(aDate);
		
		// 書き込むためのファイルを選択する。
		JFileChooser fileChooser = new JFileChooser();
		FileFilter fileFilter = new FileNameExtensionFilter("Pen (*.penBinary)", "penBinary");
		fileChooser.addChoosableFileFilter(fileFilter);
		fileChooser.setSelectedFile(new File(aString + ".penBinary"));
		int answer = fileChooser.showSaveDialog(null);
		if (answer != JFileChooser.APPROVE_OPTION) { return null; }
		File aFile = fileChooser.getSelectedFile();
		
		// 書き込むファイルがすでに存在している場合に上書きしてもいいかを問い合わせる。
		if (aFile.exists())
		{
			aString = "Really overwrite?";
			answer = JOptionPane.showConfirmDialog(null, aString, "Confirm", JOptionPane.YES_NO_OPTION, JOptionPane.PLAIN_MESSAGE);
			if (answer == JOptionPane.NO_OPTION) { return null; }
		}
		
		// ファイルに書き込む。
		try
		{
			ObjectOutputStream aStream = new ObjectOutputStream(new FileOutputStream(aFile));
			aStream.writeObject(aPen);
			aStream.close();
 		}
		catch (IOException anException)
		{
			throw new RuntimeException(anException.toString());
		}
		
		return aPen;
	}

	/**
	 * ペンのオブジェクトをファイルから読み込んで応答する。
	 */
	public static Pen read()
	{
		// 読み込むためのファイルを選択する。
		JFileChooser fileChooser = new JFileChooser();
		FileFilter fileFilter = new FileNameExtensionFilter("Pen (*.penBinary)", "penBinary");
		fileChooser.addChoosableFileFilter(fileFilter);
		int answer = fileChooser.showOpenDialog(null);
		if (answer != JFileChooser.APPROVE_OPTION) { return null; }
		File aFile = fileChooser.getSelectedFile();
		
		// ファイルから読み込む。
		Pen aPen = null;
		try
		{
			ObjectInputStream aStream = new ObjectInputStream(new FileInputStream(aFile));
			aPen = (Pen)(aStream.readObject());
			aStream.close();
 		}
		catch (IOException anException)
		{
			throw new RuntimeException(anException.toString());
		}
		catch (ClassNotFoundException anException)
		{
			throw new RuntimeException(anException.toString());
		}
		
		// 読み込んだ(復元した)ペン応答する。
		return aPen;
	}
}
