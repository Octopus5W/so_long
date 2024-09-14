#include "../include/so_long.h"

int load_map(t_game *game, const char *map_file)
{
    int fd;
    char *line;
    int i = 0;

    fd = open(map_file, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error: Could not open map file\n", 31);
        return (0);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i++] = line;
        if (i == 1)
            game->map_width = strlen(line);
    }
    game->map[i] = NULL;
    game->map_height = i;

    close(fd);
    return (1);
}
