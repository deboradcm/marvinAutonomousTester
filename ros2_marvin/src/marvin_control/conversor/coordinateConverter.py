import random

class CoordinateConverter:
    def __init__(self, screen_width=1080, screen_height=1920, 
                 x_min=-35.495777, x_max=35.495777,
                 y_min=-3.872530, y_max=3.872530,
                 z_min=-71.830040, z_max=71.830040):

        self.screen_width = screen_width
        self.screen_height = screen_height
        self.x_min = x_min
        self.x_max = x_max
        self.y_min = y_min
        self.y_max = y_max
        self.z_min = z_min
        self.z_max = z_max

    def generate_random_coordinates(self):

        x = random.uniform(self.x_min, self.x_max)
        y = random.uniform(self.y_min, self.y_max)
        z = random.uniform(self.z_min, self.z_max)
        return (x, y, z)

    def convert_to_pixel_coordinates(self, x, y, z):

        # Normalizando as coordenadas
        x_normalized = (x - self.x_min) / (self.x_max - self.x_min)
        y_normalized = (y - self.y_min) / (self.y_max - self.y_min)

        # Convertendo para coordenadas de pixel
        px = int(x_normalized * self.screen_width)
        py = int(y_normalized * self.screen_height)

        return (px, py)

# Exemplo de uso
converter = CoordinateConverter()
coordinates = converter.generate_random_coordinates()
print(f"Coordenadas Aleatórias: {coordinates}")

pixel_coordinates = converter.convert_to_pixel_coordinates(*coordinates)
print(f"Coordenadas em Pixels: {pixel_coordinates}")
