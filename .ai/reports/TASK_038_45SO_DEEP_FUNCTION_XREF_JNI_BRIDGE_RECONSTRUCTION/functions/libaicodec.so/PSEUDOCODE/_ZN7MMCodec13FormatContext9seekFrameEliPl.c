// Function: MMCodec::FormatContext::seekFrame(long, int, long*)
// RVA: 0x149b04, Size: 556 bytes
int64_t _ZN7MMCodec13FormatContext9seekFrameEliPl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec18MediaHandleContext17getKeyFrameTablesEi(...); // call imported API via PLT at 0x149b5c
    _ZN7MMCodec13KeyFrameTable8getEntryEi(...); // call imported API via PLT at 0x149b68
    avformat_index_get_entries_count(...); // call imported API via PLT at 0x149be0
    avformat_index_get_entry(...); // call imported API via PLT at 0x149bf0
    av_get_time_base_q(...); // call imported API via PLT at 0x149c34
    av_rescale_q(...); // call imported API via PLT at 0x149c44
    av_get_time_base_q(...); // call imported API via PLT at 0x149c8c
    av_rescale_q(...); // call imported API via PLT at 0x149cac
    av_seek_frame(...); // call imported API via PLT at 0x149ccc
    return a0;
    av_seek_frame(...); // call imported API via PLT at 0x149d0c
}
