"""
    merger.py
"""


def one_line_parser(line_input, directory, required_index, length):
    """
    :param line_input:
    :param directory:
    :param required_index:
    :return:
    """
    for line in line_input:
        if line[0] not in directory:
            directory[line[0]] = [0 for i in range(length)]
            directory[line[0]][required_index] = line[1]
        else:
            directory[line[0]][required_index] = line[1]
    return directory


def merge_tuples(line_a, line_b, line_c):
    """
    :param line_a:
    :param line_b:
    :param line_c:
    :return:
    """
    directory = {}
    required_index = 0
    length = max(len(line_a), len(line_b), len(line_c))

    directory = one_line_parser(line_a, directory, required_index, length)
    required_index += 1
    directory = one_line_parser(line_b, directory, required_index, length)
    required_index += 1
    directory = one_line_parser(line_c, directory, required_index, length)
    return directory


def simple_visual_test():
    """
        Test function
    """
    line_a = ((1, 3), (3, 4), (10, 2))
    line_b = ((1, 2), (2, 4), (5, 2))
    line_c = ((1, 5), (3, 2), (7, 3))
    print(merge_tuples(line_a, line_b, line_c))
