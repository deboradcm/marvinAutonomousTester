from setuptools import find_packages, setup

package_name = 'action_robo_v2'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=[
        'setuptools',
        'paho-mqtt',
        'rclpy',
    ],
    zip_safe=True,
    maintainer='equipe01',
    maintainer_email='debora.medeiros@icomp.ufam.edu.br',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'action_robo_server  = action_robo_v2.action_robo_server:main',
            'action_robo_client  = action_robo_v2.action_robo_client:main'
        ],
    },
)
