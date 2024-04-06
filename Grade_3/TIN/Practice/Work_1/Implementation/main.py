import networkx as nx
import matplotlib.pyplot as plt

# Создаем пустой граф
G = nx.Graph()

# Добавляем вершины и рёбра на основе ваших данных
edges = [(1, 2), (1, 4), (1, 5), (1, 7), (1, 8), (2, 3), (2, 4), (3, 6), (3, 7), (4, 6), (5, 6), (5, 8), (6, 7), (6, 8), (6, 9), (7, 10), (8, 9), (8, 10), (9, 10)]
weights = [15, 20, 25, 6, 43, 95, 30, 12, 10, 35, 71, 63, 50, 18, 48, 21, 90, 15, 10]

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