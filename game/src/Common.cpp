#include "Common.h"

char *Common::file_read(const char *filename) {
    SDL_RWops *rw = SDL_RWFromFile(filename, "rb");
    if (rw == nullptr) return nullptr;

    Sint64 res_size = SDL_RWsize(rw);
    char *res = (char *)malloc(res_size + 1);

    Sint64 nb_read_total = 0, nb_read = 1;
    char *buf = res;
    while (nb_read_total < res_size && nb_read != 0) {
        nb_read = SDL_RWread(rw, buf, 1, (res_size - nb_read_total));
        nb_read_total += nb_read;
        buf += nb_read;
    }
    SDL_RWclose(rw);
    if (nb_read_total != res_size) {
        free(res);
        return nullptr;
    }

    res[nb_read_total] = '\0';
    return res;
}

void Common::read_Json(json &j, const std::string &file) {
    char *data = Common::file_read(file.c_str());
    if (data == nullptr) exit(0);

    j = json::parse(data, data + strlen(data));
    free(data);
}
