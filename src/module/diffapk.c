//
// Created by 王海龙 on 2022/9/5.
//
#include "diffapk.h"
#include "bsdiff.h"
#include "bspatch.h"


JNIEXPORT void JNICALL
Java_whl_bsdiff_BsDiff_diff(JNIEnv
                            *env,
                            jobject thizz, jstring
                            oldfile_jstr,
                            jstring newfile_jstr,
                            jstring
                            patchfile_jstr) {
    if (env == NULL) {
        return;
    }
    int argc = 4;
    char *oldfile = (char *) (*env)->GetStringUTFChars(env, oldfile_jstr, NULL);
    char *newfile = (char *) (*env)->GetStringUTFChars(env, newfile_jstr, NULL);
    char *patchfile = (char *) (*env)->GetStringUTFChars(env, patchfile_jstr, NULL);

//参数（第一个参数无效）
    char *argv[4];
    argv[0] = "bsdiff";
    argv[1] = oldfile;
    argv[2] = newfile;
    argv[3] = patchfile;
    bsdiff_main(argc, argv);
    (*env)->ReleaseStringUTFChars(env, oldfile_jstr, oldfile);
    (*env)->ReleaseStringUTFChars(env, newfile_jstr, newfile);
    (*env)->ReleaseStringUTFChars(env, patchfile_jstr, patchfile);
}

JNIEXPORT void JNICALL Java_whl_bsdiff_BsDiff_patch
        (JNIEnv
         *env,
         jobject thizz, jstring
         oldfile_jstr,
         jstring newfile_jstr,
         jstring
         patchfile_jstr) {
    (*env)->PushLocalFrame(env, 0);

    if (env == NULL) {
        return;
    }
    int argc = 4;
    char *oldfile = (char *) (*env)->GetStringUTFChars(env, oldfile_jstr, NULL);
    char *newfile = (char *) (*env)->GetStringUTFChars(env, newfile_jstr, NULL);
    char *patchfile = (char *) (*env)->GetStringUTFChars(env, patchfile_jstr, NULL);

//参数（第一个参数无效）
    char *argv[4];
    argv[0] = "bspatch";
    argv[1] = oldfile;
    argv[2] = newfile;
    argv[3] = patchfile;
    patch_main(argc, argv);
    (*env)->ReleaseStringUTFChars(env, oldfile_jstr, oldfile);
    (*env)->ReleaseStringUTFChars(env, newfile_jstr, newfile);
    (*env)->ReleaseStringUTFChars(env, patchfile_jstr, patchfile);

    (*env)->PopLocalFrame(env, NULL);

}

