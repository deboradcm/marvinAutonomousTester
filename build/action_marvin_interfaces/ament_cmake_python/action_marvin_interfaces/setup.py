from setuptools import find_packages
from setuptools import setup

setup(
    name='action_marvin_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('action_marvin_interfaces', 'action_marvin_interfaces.*')),
)
