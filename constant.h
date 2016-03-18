#ifndef CONSTANT_H
#define CONSTANT_H


// working type:
// 1. track: just to check the resouce information, and collect them
// 2. download: download the resource

enum WORKING_TYPE {
    E_TRACK,
    E_DOWNLOAD
};

// resorce state
// 1. unknown
// 2. tracked : is a resource, have been tracked, but not plan to download
// 3. need download : plan to download
// 4. downloading : is in download
// 5. downloaded
enum RESOURCE_STATE {
    E_UNKNOW,
    E_TRACKED,
    E_NEED_DOWNLOAD,
    E_DOWNLOADING,
    E_DOWNLOADED
};

#endif // CONSTANT_H

