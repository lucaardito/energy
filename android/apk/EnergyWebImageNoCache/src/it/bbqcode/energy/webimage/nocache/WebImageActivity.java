package it.bbqcode.energy.webimage.nocache;

import it.bbqcode.energy.webimage.nocache.R;

import java.io.InputStream;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;

public class WebImageActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_web_image);
		// http://softeng.polito.it/ICSR13/loghi/logo_PoliTO.png
		
		SharedPreferences sharedPref = getPreferences(Context.MODE_PRIVATE);
		int id = sharedPref.getInt("id", 0);
		sharedPref.edit().putInt("id", id+1).commit();
		
		//Log.d("ID", String.valueOf(id));

		new DownloadImageTask((ImageView) findViewById(R.id.imageView1))
		.execute("http://test.bbqcode.it/mac/lp" + id%30 + ".png");
	}

	private class DownloadImageTask extends AsyncTask<String, Void, Bitmap> {
		ImageView bmImage;

		public DownloadImageTask(ImageView bmImage) {
			this.bmImage = bmImage;
		}

		protected Bitmap doInBackground(String... urls) {
			String urldisplay = urls[0];
			Bitmap mIcon11 = null;
			try {
				InputStream in = new java.net.URL(urldisplay).openStream();
				mIcon11 = BitmapFactory.decodeStream(in);
			} catch (Exception e) {
				Log.e("Error", e.getMessage());
				e.printStackTrace();
			}
			return mIcon11;
		}

		protected void onPostExecute(Bitmap result) {
			bmImage.setImageBitmap(result);
		}
	}
}
