package org.cocos2dx.cpp;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

import com.igaworks.v2.core.AdBrixRm;

import org.cocos2dx.hellocpp.R;

public class DeeplinkActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.deeplink_activity);
        onNewIntent(DeeplinkActivity.this.getIntent());
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        setIntent(intent);
        AdBrixRm.deeplinkEvent(DeeplinkActivity.this);
    }

}
