import networkx as nx
import matplotlib.pyplot as plt

# Создаем пустой граф
G = nx.Graph()

# Добавляем вершины и рёбра на основе ваших данных
edges = [
    (1, 2), (1, 3), (1, 6), (1, 7), (1, 9), (1, 10), (1, 12), (1, 13),  #8
    (2, 3), (2, 6), (2, 8), (2, 10),                                    #4
    (3, 4), (3, 5), (3, 7), (3, 9), (3, 10), (3, 15),                   #6
    (4, 6), (4, 8), (4, 11), (4, 12),                                   #4
    (5, 6), (5, 7), (5, 11), (5, 13), (5, 14), (5, 15),                 #6
    (6, 9), (6, 10), (6, 12), (6, 15),                                  #4
    (7, 8), (7, 10), (7, 12), (7, 13),                                  #4
    (8, 11), (8, 13), (8, 15),                                          #3
    (9, 12), (9, 13),                                                   #2
    (10, 11), (10, 12), (10, 13),                                       #3
    (12, 15),                                                           #1
    (13, 14), (13, 15),                                                 #2
    (14, 15)                                                            #1
]

weights = [
    90, 70, 85, 95, 110, 80, 75, 130,
    80, 110, 100, 125,
    100, 75, 95, 140, 130, 105,
    120, 105, 50, 85,
    70, 55, 115, 85, 130, 60,
    95, 100, 115, 70,
    80, 115, 90, 100,
    65, 80, 100,
    90, 85,
    95, 75, 65,
    115,
    90, 110,
    85
]

# Добавляем номера рёбер
edges_with_labels = {}
for i, edge in enumerate(edges):
    G.add_edge(edge[0], edge[1])
    edges_with_labels[edge] = i + 1

# Рисуем граф с номерами рёбер и весами на рёбрах
pos = nx.spring_layout(G)
nx.draw(G, pos, with_labels=True, node_size=300)
edge_labels = {edge: str(label) + '\n' + str(weight) for edge, label, weight in zip(edges, range(1, len(edges) + 1), weights)}
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10, font_color='blue', bbox=dict(facecolor='white', edgecolor='none', boxstyle='round'))
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10, font_color='red', bbox=dict(facecolor='white', edgecolor='none', boxstyle='round'), label_pos=0.5)
plt.show()