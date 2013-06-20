package primeministers;

import java.util.ArrayList;
import java.io.File;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.net.URL;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.net.MalformedURLException;
import java.io.OutputStreamWriter;
import java.lang.String;


/**
 * 入出力：リーダ・ダウンローダ・ライタを抽象する。
 */
public abstract class IO extends Object
{
	/**
	 * テーブル（表：スプレッドシート）を記憶するフィールド。
	 */
	protected Table table;
    
	/**
	 * 入出力のコンストラクタ。
	 */
	public IO()
	{
		super();
		this.table = null;
		return;
	}
	
	/**
	 *  総理大臣ページのためのディレクトリ（存在しなければ作成して）を応答するクラスメソッド。
	 */
	public static File directoryOfPages()
	{
        String aString = System.getProperty("user.home");
        aString = aString + File.separator + "Desktop" + File.separator + "PrimeMinisters";
        File aDirectory = new File(aString);
        if(!aDirectory.exists())
        {
            aDirectory.mkdir();
        }
        
        return aDirectory;
                
	}
	
	/**
	 * 入出力する際の文字コードを応答するクラスメソッド。
	 */
	public static String encodingSymbol()
	{
		return "UTF-8";
	}
	
	/**
	 * 指定されたファイルからテキストを読み込んで、それを行リストにして応答するクラスメソッド。
	 */
	public static ArrayList<String> readTextFromFile(File aFile) {
		ArrayList<String> anArrayList = new ArrayList<String>();
		// BufferedReaderの例外処理
		try {
			//BufferedReader aBufferedReader = new BufferedReader(new FileReader(aFile));
			
			BufferedReader aBufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(aFile),IO.encodingSymbol()));
			String aLine = "";
			while ((aLine = aBufferedReader.readLine()) != null) {
				anArrayList.add(aLine);
			}
			aBufferedReader.close();

		} catch (FileNotFoundException e) {
			// ファイルオブジェクト生成時の例外捕捉
			e.printStackTrace();

		} catch (IOException e) {
			// バッファードリーダーオブジェクトのクローズ時の例外捕捉
			e.printStackTrace();

		}
		return anArrayList;

	}

	/**
	 * 指定されたファイル文字列からテキストを読み込んで、それを行リストにして応答するクラスメソッド。
	 */
	public static ArrayList<String> readTextFromFile(String fileString) {
        //上のメッセージと連動
		File aFile = new File(fileString);
        return IO.readTextFromFile(aFile);
		
	}
	
	/**
	 * 指定されたURL文字列からテキストを読み込んで、それを行リストにして応答するクラスメソッド。
	 */
	public static ArrayList<String> readTextFromURL(String urlString)
	{
        //下のメッセージと連動
		URL aURL = null;
        try{
            aURL = new URL(urlString);
            
        }catch(MalformedURLException e){
            e.printStackTrace();
            
        }
        ArrayList<String> anArrayList = new ArrayList<String>(); 
        anArrayList = IO.readTextFromURL(aURL);
		return anArrayList;
		
	}
	
	/**
	 * 指定されたURLからテキストを読み込んで、それを行リストにして応答するクラスメソッド。
	 */
	public static ArrayList<String> readTextFromURL(URL aURL)
	{
		ArrayList<String> anArrayList = new ArrayList<String>();
         try{
        InputStream anInputStream = aURL.openStream();
        InputStreamReader anInputStreamReader = new InputStreamReader(anInputStream, IO.encodingSymbol());
        BufferedReader aBufferedReader = new BufferedReader(anInputStreamReader);
        String aLine = "";
        while((aLine = aBufferedReader.readLine()) != null)
        {
            anArrayList.add(aLine);
        }
        aBufferedReader.close();
        
    }catch(FileNotFoundException e){
        //ファイルオブジェクト生成時の例外捕捉
        e.printStackTrace();
        
    }catch(IOException e){
        //バッファードリーダーオブジェクトのクローズ時の例外捕捉
        e.printStackTrace();
        
    }
    return anArrayList;

		
	}
	
	/**
	 *  文字列をセパレータで分割したトークン列を応答するクラスメソッド。
	 */
	public static ArrayList<String> splitString(String string,String separators)
	{
		ArrayList<String> anArrayList = new ArrayList<String>();
		ArrayList<Integer> separetorsIndex = new ArrayList<Integer>();
		int index,stop;
		int start,end;
		stop = string.length();
		separetorsIndex.add(-1);
		for(index = 0; index < stop; index++)
		{
			if(separators.indexOf(string.charAt(index)) >= 0)
			{
				separetorsIndex.add(index);
			}
		}
		separetorsIndex.add(stop);
		stop = separetorsIndex.size() - 1;
		for(index = 0; index < stop; index++)
		{
			start = separetorsIndex.get(index) + 1;
			end = separetorsIndex.get(index + 1);
			if(end > start)
			{
				anArrayList.add(string.substring(start,end));
				
			}
		}
		return anArrayList;
	}
	
	/**
	 * テーブルを応答する。
	 */
	public Table table()
	{
		return this.table;

	}
	
	/**
	 * 指定された行リストを、指定されたファイルに書き出すクラスメソッド。
	 */
	public static void writeText(ArrayList<String> aCollection, File aFile)
	{
    try{
        FileOutputStream aFileOutputStream = new FileOutputStream(aFile);
        OutputStreamWriter aOutputStreamWriter = new OutputStreamWriter(aFileOutputStream, IO.encodingSymbol());
        BufferedWriter aBufferedWriter = new BufferedWriter(aOutputStreamWriter);
    for(String aString : aCollection)
        {
        aBufferedWriter.write(aString);
        aBufferedWriter.write("\n");

        }       
        aBufferedWriter.close();
    }catch(IOException e){
        e.printStackTrace();
    }
		return;
	}
	
	/**
	 * 指定された行リストを、指定されたファイル名のファイルに書き出すクラスメソッド。
	 */
	public static void writeText(ArrayList<String> aCollection, String fileString)
	{
        File aFile = new File(fileString);
        IO.writeText(aCollection,aFile);
		return;
	
	}
}
