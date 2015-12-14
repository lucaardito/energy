package it.bbqcode.energy.image.sd;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Environment;
import android.widget.ImageView;
import it.bbqcode.energy.image.sd.R;

public class ImageActivity extends Activity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_image);

		String pathName = Environment.getExternalStorageDirectory().getPath() + "/Pictures/lp1.png";
		((ImageView) findViewById(R.id.imageView)).setImageBitmap(BitmapFactory.decodeFile(pathName));
		
		// Use this method if the source image causes crash (Out of Memory Exception)
		//((ImageView) findViewById(R.id.imageView)).setImageBitmap(decodeFile(img));
	}

	// Decodes image and scales it to reduce memory consumption
	@SuppressWarnings("unused")
	private Bitmap decodeFile(File f){
		Bitmap b = null;
		int IMAGE_MAX_SIZE = 2048; // Adjust this if necessary
		try {
			//Decode image size
			BitmapFactory.Options o = new BitmapFactory.Options();
			o.inJustDecodeBounds = true;

			FileInputStream fis = new FileInputStream(f);
			BitmapFactory.decodeStream(fis, null, o);
			fis.close();

			int scale = 1;
			if (o.outHeight > IMAGE_MAX_SIZE || o.outWidth > IMAGE_MAX_SIZE) {
				scale = (int)Math.pow(2, (int) Math.ceil(Math.log(IMAGE_MAX_SIZE / 
						(double) Math.max(o.outHeight, o.outWidth)) / Math.log(0.5)));
			}

			//Decode with inSampleSize
			BitmapFactory.Options o2 = new BitmapFactory.Options();
			o2.inSampleSize = scale;
			fis = new FileInputStream(f);
			b = BitmapFactory.decodeStream(fis, null, o2);
			fis.close();
		} catch (IOException e) {}
		return b;
	}
}
