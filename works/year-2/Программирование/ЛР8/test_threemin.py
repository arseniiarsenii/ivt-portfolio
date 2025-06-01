from hypothesis import given, strategies as st
import pytest
from threemin import threemin, threemin_naive


def test_treemin_raises_exception_short_list() -> None:
    test_list = [1, 2]
    with pytest.raises(ValueError):
        threemin(test_list)


def test_treemin_raises_exception_not_a_list() -> None:
    test_list = (1, 2, 3)
    with pytest.raises(TypeError):
        threemin(test_list)


def test_treemin_raises_exception_wrong_member_type() -> None:
    test_list = [1, 2, None]
    with pytest.raises(TypeError):
        threemin(test_list)


def test_treemin_normal_list() -> None:
    test_list = [i for i in range(-10, 11)]
    target = threemin_naive(test_list)
    res = threemin(test_list)
    assert res == target, f"Ожидалось: {target}; Получено: {res}"


def test_treemin_only_positives() -> None:
    test_list = [i for i in range(1, 21)]
    target = threemin_naive(test_list)
    res = threemin(test_list)
    assert res == target, f"Ожидалось: {target}; Получено: {res}"


def test_treemin_only_negatives() -> None:
    test_list = [i for i in range(-20, 0)]
    target = threemin_naive(test_list)
    res = threemin(test_list)
    assert res == target, f"Ожидалось: {target}; Получено: {res}"


def test_treemin_all_zeros() -> None:
    test_list = [0] * 20
    target = threemin_naive(test_list)
    res = threemin(test_list)
    assert res == target, f"Ожидалось: {target}; Получено: {res}"


def test_treemin_very_large_list() -> None:
    test_list = [i for i in range(-1000, 1001)]
    target = -999000000
    res = threemin(test_list)
    assert res == target, f"Ожидалось: {target}; Получено: {res}"


@given(st.lists(st.integers(), min_size=3))
def test_treemin_w_hypothesis(test_list) -> None:
    target = threemin_naive(test_list)
    res = threemin(test_list)
    assert res == target, f"Ожидалось: {target}; Получено: {res}"
