package primeministers;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import javax.imageio.ImageIO;

/**
 * ダウンローダ：総理大臣のCSVファイル・画像ファイル・サムネイル画像ファイルをダウンロードする。
 */
public class Downloader extends IO
{
	/**
	 * 総理大臣の情報を記したCSVファイルの在処(URL文字列)を記憶するフィールド。
	 */
	private String url;

	/**
	 * ダウンローダのコンストラクタ。
	 */
	public Downloader()
	{
		super();
		url = Downloader.urlStringOfCSV(); 
		return;
	}

	/**
	 * 総理大臣の情報を記したCSVファイルをダウンロードする。
	 */
	public void downloadCSV()
	{
		ArrayList<String> anArrayList = Downloader.readTextFromURL(this.url);
		File aFile = Reader.filenameOfCSV();
		Downloader.writeText(anArrayList,aFile);

		return;
	}

	/**
	 * 総理大臣の画像群をダウンロードする。
	 */
	public void downloadImages()
	{
		int indexOfImages = this.table().attributes().indexOfImage();
		this.downloadPictures(indexOfImages);
		return;
	}

	/**
	 * 総理大臣のサムネイル画像群をダウンロードする。
	 */
	public void downloadThumbnails()
	{
		int indexOfThumbnails = this.table().attributes().indexOfThumbnail();
		this.downloadPictures(indexOfThumbnails);
		return;
	}
	/**
	 * 総理大臣の画像群やサムネイル画像群をダウンロードする。
	 */
	private void downloadPictures(int indexOfPictures)
	{

		for(Tuple aTuple : this.table().tuples())
		{

			String theString = aTuple.values().get(indexOfPictures);
			
			String aString = this.urlString() + theString;
			//ufferedImage anImage = ImageUtility.readImageFromURL(aString);
			
			URL aURL = null;
			try{ aURL = new URL(aString); }
			catch (MalformedURLException anException)
			{anException.printStackTrace();}
			BufferedImage anImage = null;
			try { anImage = ImageIO.read(aURL); }
			catch (IOException anException) { anException.printStackTrace(); }
			
			ArrayList<String> aCollection = Downloader.splitString(theString, "/");
			StringBuffer aBuffer = new StringBuffer();
			int lastIndex = aCollection.size() - 1;
			for(int index = 0; index < lastIndex; index++)
			{
				aBuffer.append(aCollection.get(index));
				aBuffer.append(File.separator);
			}
			aString = aBuffer.toString() + aCollection.get(lastIndex);
			File aDirectory = Downloader.directoryOfPages();
			File aFile = new File(aDirectory.getPath() + File.separator + aString );
			System.out.println("==>" + aFile);
			aDirectory = new File(aFile.getParent());
			if(!aDirectory.exists())
			{
				aDirectory.mkdir();
			}
			  aString = aFile.getName();              // aFileの抽象パス名が示すファイルの名前をaStringに束縛。
              aString = aString.substring(aString.lastIndexOf(".") + 1);              // aStringの部分文字列として、引数のインデックスから始まる新しい文字列をaStringに束縛。引数内のlastIndexOf(".")とは、aStringの文字列内で指定された部分文字列"."が一番右に出現する位置のインデックス。（例5：例1より "jpg"）
              try { ImageIO.write(anImage, aString, aFile); }         // aFileに指定された拡張子aStringでanImageを書き込む。
              catch (IOException anException) { anException.printStackTrace(); }
      
		}
		return;
	}
	/**
	 * 総理大臣の情報を記したCSVファイルをダウンロードして、画像群やサムネイル画像群をダウンロードし、テーブルで応答する。
	 */
	public Table table()
	{
		if(!(this.table == null))
		{
			return this.table;
		}
		this.downloadCSV();
		Reader aReader = new Reader();
		this.table = aReader.table();
		this.downloadImages();
		this.downloadThumbnails();
		
		return this.table;
	}

	/**
	 *  総理大臣の情報を記したCSVファイルの在処(URL)を文字列で応答する。
	 */
	public String url()
	{	
		return this.url;
	}

	/**
	 * 総理大臣の情報の在処(URL)を文字列で応答するクラスメソッド。
	 */
	public static String urlString()
	{
		return  "http://www.cc.kyoto-su.ac.jp/~atsushi/Programs/CSV2HTML/PrimeMinisters/";
	}

	/**
	 * 総理大臣の情報を記したCSVファイルの在処(URL)を文字列で応答するクラスメソッド。
	 */
	static String urlStringOfCSV()
	{
		return Downloader.urlString() + "PrimeMinisters.csv";
	}
}
