from cs50 import get_int
from csv import DictReader

def main():
    min_tempo = get_int("Min Tempo: ")
    max_tempo = get_int("Max Tempo: ")

    playlist = []
    filename = "2018_top100.csv"

    # TODO: Read song from 2018_top100.csv into playlist
    with open(filename) as file:
        file_reader = DictReader(file)
        for song in file_reader:
            if float(song["tempo"]) > min_tempo and float(song["tempo"]) < max_tempo:
                playlist.append(song["name"])

    # TODO: Print song titles from playlist
    for songs in playlist:
        print(songs)

main()
