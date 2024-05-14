
#include "encoding/qbech32.hpp"
#undef NDEBUG
#include <QDebug>
#include <assert.h>
/*
 *
 *https://github.com/iotaledger/tips/blob/main/tips/TIP-0031/tip-0031.md
 *
 */
using namespace qencoding::qbech32;

int main(int argc, char **argv)
{

    auto serialized = QByteArray::fromHex("d4a88f466009813f3b7db9d3090d1a23982238fde3f8f43fca595e57857d22ef");
    auto btcstr = SegWit::encode(QString("bc"), serialized);
    assert(btcstr == QString("bc1q6j5g73nqpxqn7wmah8fsjrg6ywvzyw8au0u0g072t9090ptayths4vdyhy"));

    auto var = SegWit::decode(btcstr);
    assert(var.first == QString("bc"));
    assert(var.second == serialized);

    // Ed25519 Address

    serialized = QByteArray::fromHex("00efdc112efe262b304bcf379b26c31bad029f616ee3ec4aa6345a366e4c9e43a3");
    auto iotastr = Iota::encode(QString("iota"), serialized);
    assert(iotastr == QString("iota1qrhacyfwlcnzkvzteumekfkrrwks98mpdm37cj4xx3drvmjvnep6xqgyzyx"));
    iotastr = Iota::encode("atoi", serialized);
    assert(iotastr == QString("atoi1qrhacyfwlcnzkvzteumekfkrrwks98mpdm37cj4xx3drvmjvnep6x8x4r7t"));
    iotastr = Iota::encode("smr", serialized);
    assert(iotastr == QString("smr1qrhacyfwlcnzkvzteumekfkrrwks98mpdm37cj4xx3drvmjvnep6xhcazjh"));
    iotastr = Iota::encode("rms", serialized);
    assert(iotastr == QString("rms1qrhacyfwlcnzkvzteumekfkrrwks98mpdm37cj4xx3drvmjvnep6xrlkcfw"));

    auto varIota = Iota::decode(iotastr);
    assert(varIota.first == QString("rms"));
    assert(varIota.second == serialized);

    // Alias Address

    serialized = QByteArray::fromHex("08fe80c2eb7c736da2f7c98ecf135ee9e34e4e076afe6e1dfebc9ec578b8f56d2f");
    iotastr = Iota::encode("iota", serialized);
    assert(iotastr == QString("iota1prlgpsht03ekmghhex8v7y67a835uns8dtlxu807hj0v279c74kj76j6rev"));
    iotastr = Iota::encode("atoi", serialized);
    assert(iotastr == QString("atoi1prlgpsht03ekmghhex8v7y67a835uns8dtlxu807hj0v279c74kj7autzrp"));

    varIota = Iota::decode(iotastr);
    assert(varIota.first == QString("atoi"));
    assert(varIota.second == serialized);

    return 0;
}
